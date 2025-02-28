#include <wx/wx.h>
#include <wx/combobox.h>
#include <wx/listbox.h>
#include <sqlite3.h>
//#include <vector>
#include <string>

// Definiert die Klasse MyApp,
// die von der wx- Klasse wxApp erbt
class MyApp : public wxApp
{
public:
    // zunächst nur eine Methode, definiert ab Zeile 45
    // soll nur den Frame anzeigen
    virtual bool OnInit();
};

// Definiert die Klasse MyFrame,
// die von der wx- Klasse wxFrame erbt

class MyFrame : public wxFrame
{
public:
    MyFrame();

private:
    // Die Methoden von MyFrame
    void OnComboBoxSelect(wxCommandEvent& event);
    void OnButtonClick(wxCommandEvent& event);
    void LoadRestaurants();
    void LoadMenuItems(int restaurantId);
    double CalculateTotalPrice();

    // Die grafischen Elemente
    wxComboBox* m_comboBox;
    wxListBox* m_listBox;
    wxButton* m_button;
    wxStaticText* m_label;
    // Der Pointer auf die SQLite- DB
    sqlite3* m_db;
};

wxIMPLEMENT_APP(MyApp);

bool MyApp::OnInit()
{
    MyFrame* frame = new MyFrame();
    frame->Show(true);
    return true;
}

// MyFrame- Konstruktor legt Dimensionen und Positionen fest
// Außerdem werden die Bindings definiert
// (also welche Methoden sind mit den grafischen Elementen verknüpft
MyFrame::MyFrame()
    : wxFrame(NULL, wxID_ANY, "Restaurant Menu", wxDefaultPosition, wxSize(400, 300))
{
    wxPanel* panel = new wxPanel(this);

    m_comboBox = new wxComboBox(panel, wxID_ANY, "", wxPoint(10, 10), wxSize(200, -1));
    m_listBox = new wxListBox(panel, wxID_ANY, wxPoint(10, 50), wxSize(200, 100), 0, NULL, wxLB_MULTIPLE);
    m_button = new wxButton(panel, wxID_ANY, "Calculate Total", wxPoint(10, 170));
    m_label = new wxStaticText(panel, wxID_ANY, "Total: 0.00", wxPoint(10, 200));

    m_comboBox->Bind(wxEVT_COMBOBOX, &MyFrame::OnComboBoxSelect, this);
    m_button->Bind(wxEVT_BUTTON, &MyFrame::OnButtonClick, this);

    // Hier wird die SQLite DB geöffnet und die
    // Restaurants aus der Datenbank geladen.
    sqlite3_open("restaurants.db", &m_db);
    LoadRestaurants(); // definiert ab Zeile 74
}

void MyFrame::LoadRestaurants()
{
    sqlite3_stmt* stmt;
    const char* query = "SELECT name FROM Restaurants";
    sqlite3_prepare_v2(m_db, query, -1, &stmt, NULL);

    while (sqlite3_step(stmt) == SQLITE_ROW) {
        const unsigned char* name = sqlite3_column_text(stmt, 0);
        // Hier wird die Liste in die Combobox gehangen
        m_comboBox->Append(wxString::FromUTF8((const char*)name));
    }

    sqlite3_finalize(stmt);
}

void MyFrame::LoadMenuItems(int restaurantId)
{
    m_listBox->Clear();

    sqlite3_stmt* stmt;
    const char* query = "SELECT name FROM MenuItems WHERE restaurant_id = ?";
    sqlite3_prepare_v2(m_db, query, -1, &stmt, NULL);
    sqlite3_bind_int(stmt, 1, restaurantId);

    while (sqlite3_step(stmt) == SQLITE_ROW) {
        const unsigned char* name = sqlite3_column_text(stmt, 0);
        m_listBox->Append(wxString::FromUTF8((const char*)name));
    }

    sqlite3_finalize(stmt);
}

void MyFrame::OnComboBoxSelect(wxCommandEvent& event)
{
    int selectedIndex = m_comboBox->GetSelection();
    if (selectedIndex != wxNOT_FOUND) {
        LoadMenuItems(selectedIndex + 1); // Restaurant IDs beginnen mit 1
    }
}

void MyFrame::OnButtonClick(wxCommandEvent& event)
{
    double totalPrice = CalculateTotalPrice();
    m_label->SetLabel(wxString::Format("Total: %.2f", totalPrice));
}

double MyFrame::CalculateTotalPrice()
{
    double totalPrice = 0.0;
    wxArrayInt selections;
    m_listBox->GetSelections(selections);

    sqlite3_stmt* stmt;
    const char* query = "SELECT price FROM MenuItems WHERE name = ?";
    sqlite3_prepare_v2(m_db, query, -1, &stmt, NULL);

    for (int selection : selections) {
        wxString itemName = m_listBox->GetString(selection);
        sqlite3_bind_text(stmt, 1, itemName.ToUTF8(), -1, SQLITE_STATIC);

        if (sqlite3_step(stmt) == SQLITE_ROW) {
            totalPrice += sqlite3_column_double(stmt, 0);
        }

        sqlite3_reset(stmt);
    }

    sqlite3_finalize(stmt);
    return totalPrice;
}

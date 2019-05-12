#ifndef PARTICULARS_H
#define PARTICULARS_H
#include <wx/dialog.h>

class Particulars: public wxDialog
{
    DECLARE_CLASS( Particulars )
    DECLARE_EVENT_TABLE()
    public:
        Particulars();
        Particulars(wxWindow *parrent, wxWindowID = wxID_ANY,
                    const wxString& caption = wxT("Ships Particulars"),
                    const wxPoint& pos = wxDefaultPosition,
                    const wxSize& size = wxDefaultSize,
                    long style = wxCAPTION|wxRESIZE_BORDER|wxSYSTEM_MENU );
        void Init();

        bool Create(wxWindow *parrent, wxWindowID = wxID_ANY,
                    const wxString& caption = wxT("Ships Particulars"),
                    const wxPoint& pos = wxDefaultPosition,
                    const wxSize& size = wxDefaultSize,
                    long style = wxCAPTION|wxRESIZE_BORDER|wxSYSTEM_MENU );
        void CreateControls();
        virtual ~Particulars();

    protected:

    private:
};

#endif // PARTICULARS_H

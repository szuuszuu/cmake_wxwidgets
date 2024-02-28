#include <wx/wx.h>
#include <iostream>
#include <string>

class MainFrame : public wxFrame
{
    public:
        MainFrame(const wxString& title, int width, int height);

    private:

        wxPanel *panel;

        wxBoxSizer *mainSizer, *subSizer, *textSizer, *keypadbutton_2, *keypadSizer;
        wxGridSizer *keypadbutton_1;

        wxTextCtrl *output;

        double result = 0;
        std::string left_side = "";
        std::string right_side = "";
        wxString result_str = "";

        enum OPERATION {ADD, SUB, MUL, DIV, CLEAR};
        enum SIDE {LEFT, RIGHT};

        SIDE currentSide = LEFT;
        OPERATION currentOperation = CLEAR;

        void ButtonClicked_Numbers(wxCommandEvent& evt);
        void ButtonClicked_Operation(wxCommandEvent& evt);
        void OnButton_DEC(wxCommandEvent& evt);
        void Equation();
        void OnButton_EQ(wxCommandEvent& evt);
        void OnButton_CLR(wxCommandEvent& evt);
        void Update();
        wxDECLARE_EVENT_TABLE();
};
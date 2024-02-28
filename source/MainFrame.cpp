#include "MainFrame.h"
#include <wx/wx.h>
#include <iostream>
#include <string>
#include <algorithm>

enum IDs {
    BUTTON_0 = 100,
    BUTTON_1 = 101,
    BUTTON_2 = 102,
    BUTTON_3 = 103,
    BUTTON_4 = 104,
    BUTTON_5 = 105,
    BUTTON_6 = 106,
    BUTTON_7 = 107,
    BUTTON_8 = 108,
    BUTTON_9 = 109,
    BUTTON_DEC = 110,
    BUTTON_EQ = 111,
    BUTTON_CLR = 112,
    BUTTON_ADD = 200,
    BUTTON_SUB = 201,
    BUTTON_MUL = 202,
    BUTTON_DIV = 203,
    TEXT_OUTPUT = 117,

};

wxBEGIN_EVENT_TABLE(MainFrame, wxFrame)
    EVT_BUTTON(BUTTON_DEC,MainFrame::OnButton_DEC)
    EVT_BUTTON(BUTTON_EQ,MainFrame::OnButton_EQ)
    EVT_BUTTON(BUTTON_CLR,MainFrame::OnButton_CLR)
wxEND_EVENT_TABLE()

MainFrame::MainFrame(const wxString& title, int width, int height): 
wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(width, height))
{
    Centre();

    wxBoxSizer *mainSizer = new wxBoxSizer(wxVERTICAL);
    wxPanel *panel = new wxPanel(this);
    mainSizer->Add(panel, 1);
    this->SetSizer(mainSizer);

    wxBoxSizer *subSizer = new wxBoxSizer(wxVERTICAL);
    panel->SetSizer(subSizer);

    wxBoxSizer *textSizer = new wxBoxSizer(wxHORIZONTAL);
    output = new wxTextCtrl(panel, TEXT_OUTPUT, "", wxDefaultPosition, wxDefaultSize, wxTE_READONLY);
    textSizer->Add(output, 1, wxRIGHT | wxLEFT | wxTOP, 10);
    subSizer->Add(textSizer, 0, wxEXPAND);

    wxButton *Button_dummy = new wxButton(panel, wxID_ANY, "", wxDefaultPosition, wxSize(50,50));
    Button_dummy->Enable(false);
    wxButton *Button_0 = new wxButton(panel, BUTTON_0, "0", wxDefaultPosition, wxSize(50,50));
    wxButton *Button_1 = new wxButton(panel, BUTTON_1, "1", wxDefaultPosition, wxSize(50,50));
    wxButton *Button_2 = new wxButton(panel, BUTTON_2, "2", wxDefaultPosition, wxSize(50,50));
    wxButton *Button_3 = new wxButton(panel, BUTTON_3, "3", wxDefaultPosition, wxSize(50,50));
    wxButton *Button_4 = new wxButton(panel, BUTTON_4, "4", wxDefaultPosition, wxSize(50,50));
    wxButton *Button_5 = new wxButton(panel, BUTTON_5, "5", wxDefaultPosition, wxSize(50,50));
    wxButton *Button_6 = new wxButton(panel, BUTTON_6, "6", wxDefaultPosition, wxSize(50,50));
    wxButton *Button_7 = new wxButton(panel, BUTTON_7, "7", wxDefaultPosition, wxSize(50,50));
    wxButton *Button_8 = new wxButton(panel, BUTTON_8, "8", wxDefaultPosition, wxSize(50,50));
    wxButton *Button_9 = new wxButton(panel, BUTTON_9, "9", wxDefaultPosition, wxSize(50,50));
    wxButton *Button_DEC = new wxButton(panel, BUTTON_DEC, ".", wxDefaultPosition, wxSize(50,50));
    wxButton *Button_EQ = new wxButton(panel, BUTTON_EQ, "=", wxDefaultPosition, wxSize(50,50));
    wxButton *Button_CLR = new wxButton(panel, BUTTON_CLR, "CLR", wxDefaultPosition, wxSize(50,50));
    wxButton *Button_ADD = new wxButton(panel, BUTTON_ADD, "+", wxDefaultPosition, wxSize(50,50));
    wxButton *Button_SUB = new wxButton(panel, BUTTON_SUB, "-", wxDefaultPosition, wxSize(50,50));
    wxButton *Button_MUL = new wxButton(panel, BUTTON_MUL, "*", wxDefaultPosition, wxSize(50,50));
    wxButton *Button_DIV = new wxButton(panel, BUTTON_DIV, "/", wxDefaultPosition, wxSize(50,50));

    Button_0->Bind(wxEVT_BUTTON, &MainFrame::ButtonClicked_Numbers, this);
    Button_1->Bind(wxEVT_BUTTON, &MainFrame::ButtonClicked_Numbers, this);
    Button_2->Bind(wxEVT_BUTTON, &MainFrame::ButtonClicked_Numbers, this);
    Button_3->Bind(wxEVT_BUTTON, &MainFrame::ButtonClicked_Numbers, this);
    Button_4->Bind(wxEVT_BUTTON, &MainFrame::ButtonClicked_Numbers, this);
    Button_5->Bind(wxEVT_BUTTON, &MainFrame::ButtonClicked_Numbers, this);
    Button_6->Bind(wxEVT_BUTTON, &MainFrame::ButtonClicked_Numbers, this);
    Button_7->Bind(wxEVT_BUTTON, &MainFrame::ButtonClicked_Numbers, this);
    Button_8->Bind(wxEVT_BUTTON, &MainFrame::ButtonClicked_Numbers, this);
    Button_9->Bind(wxEVT_BUTTON, &MainFrame::ButtonClicked_Numbers, this);
    Button_ADD->Bind(wxEVT_BUTTON, &MainFrame::ButtonClicked_Operation, this);
    Button_SUB->Bind(wxEVT_BUTTON, &MainFrame::ButtonClicked_Operation, this);
    Button_MUL->Bind(wxEVT_BUTTON, &MainFrame::ButtonClicked_Operation, this);
    Button_DIV->Bind(wxEVT_BUTTON, &MainFrame::ButtonClicked_Operation, this);


    wxGridSizer *keypadbutton_1 = new wxGridSizer(4,4,5,5);
    keypadbutton_1->Add(Button_7);
    keypadbutton_1->Add(Button_8);
    keypadbutton_1->Add(Button_9);
    keypadbutton_1->Add(Button_MUL);
    keypadbutton_1->Add(Button_4);
    keypadbutton_1->Add(Button_5);
    keypadbutton_1->Add(Button_6);
    keypadbutton_1->Add(Button_DIV);
    keypadbutton_1->Add(Button_1);
    keypadbutton_1->Add(Button_2);
    keypadbutton_1->Add(Button_3);
    keypadbutton_1->Add(Button_ADD);
    keypadbutton_1->Add(Button_dummy);
    keypadbutton_1->Add(Button_0);
    keypadbutton_1->Add(Button_DEC);
    keypadbutton_1->Add(Button_SUB);

    wxBoxSizer *keypadbutton_2 = new wxBoxSizer(wxVERTICAL);
    keypadbutton_2->Add(Button_CLR, 2, wxEXPAND, 10);
    keypadbutton_2->Add(Button_EQ, 2, wxEXPAND, 10);

    wxBoxSizer *keypadSizer = new wxBoxSizer(wxHORIZONTAL);
    keypadSizer->Add(keypadbutton_1, 3, wxEXPAND, 10);
    keypadSizer->Add(keypadbutton_2, 1, wxEXPAND);

    subSizer->Add(keypadSizer);
}

void MainFrame::Equation(){

    result_str = std::to_string(result);
    result_str.erase ( result_str.find_last_not_of('0') + 1, std::string::npos );
    result_str.erase ( result_str.find_last_not_of('.') + 1, std::string::npos );

    left_side = result_str;
    right_side = "";

    currentSide = RIGHT;
    currentOperation = CLEAR;

    Update();
}

void MainFrame::OnButton_EQ(wxCommandEvent& evt){
    double left = std::stod(left_side);
    double right = std::stod(right_side);
    
    switch (currentOperation){
        case ADD:
            result = left + right;
            Equation();
            break;
        case SUB:
            result = left - right;
            Equation();
            break;
        case MUL:
            result = left * right;
            Equation();
            break;
        case DIV:
            if (right_side == "0"){
                output->ChangeValue("ERROR");
            }
            else{
                result = left / right;
                Equation(); 
            }       
            break;
        case CLEAR:
            break;   
    }
}

void MainFrame::OnButton_DEC(wxCommandEvent& evt){
    if(currentSide == LEFT && left_side != "" && left_side.find('.') == std::string::npos){
        left_side += '.'; 
        result_str += '.'; 
    }

    if(currentSide == RIGHT && right_side != "" && right_side.find('.') == std::string::npos){
        right_side += '.'; 
        result_str += '.';     
    }
    Update();    
}


void MainFrame::OnButton_CLR(wxCommandEvent& evt){
    currentOperation = CLEAR;
    currentSide = LEFT;
    left_side = "";
    right_side = "";
    result_str = "";
    result = 0;
    Update();
}

void MainFrame::ButtonClicked_Operation(wxCommandEvent& evt){

    wxWindow* button = dynamic_cast<wxWindow*>(evt.GetEventObject());
    int id = button->GetId();
    wxString label = button->GetLabel();
    wxString tmp = output->GetValue();

    if( tmp != "" ){
        if( currentOperation == CLEAR ){
            currentSide = RIGHT;
            currentOperation = OPERATION(id-200);
            result_str += label; 
        }
        else if ( currentOperation != CLEAR  && OPERATION(id-200) == SUB ){
            currentSide = RIGHT;
            right_side += label;
            result_str += label; 
        }
    }
    else if ( tmp == "" && OPERATION(id-200) == SUB ){
        left_side += label;
        result_str += label; 
    }
    Update();
}

void MainFrame::ButtonClicked_Numbers(wxCommandEvent& evt){

    wxWindow* button = dynamic_cast<wxWindow*>(evt.GetEventObject());
    wxString label = button->GetLabel();

    if(currentSide == LEFT){
        left_side += label;
    }
    else{
        right_side += label;
    }
    result_str += label;
    Update();
}

void MainFrame::Update(){
    output->ChangeValue(result_str);
}
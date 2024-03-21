///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Jun 30 2011)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "GUIClass.h"

///////////////////////////////////////////////////////////////////////////

GUIClass::GUIClass( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	this->SetFont( wxFont( 12, 74, 93, 90, false, wxT("Comic Sans MS") ) );
	
	wxFlexGridSizer* fgSizer1;
	fgSizer1 = new wxFlexGridSizer( 10, 2, 0, 0 );
	fgSizer1->SetFlexibleDirection( wxBOTH );
	fgSizer1->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	
	fgSizer1->Add( 100, 0, 1, wxEXPAND, 5 );
	
	wxGridSizer* gSizer3;
	gSizer3 = new wxGridSizer( 3, 3, 0, 0 );
	
	topleft = new wxBitmapButton( this, wxID_ANY, wxBitmap( wxT("images/empty_soup.png"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxSize( -1,-1 ), wxBU_AUTODRAW );
	gSizer3->Add( topleft, 0, wxALL, 5 );
	
	topmid = new wxBitmapButton( this, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	gSizer3->Add( topmid, 0, wxALL, 5 );
	
	topright = new wxBitmapButton( this, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	gSizer3->Add( topright, 0, wxALL, 5 );
	
	midleft = new wxBitmapButton( this, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	gSizer3->Add( midleft, 0, wxALL, 5 );
	
	midmid = new wxBitmapButton( this, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	gSizer3->Add( midmid, 0, wxALL, 5 );
	
	midright = new wxBitmapButton( this, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	gSizer3->Add( midright, 0, wxALL, 5 );
	
	bottomleft = new wxBitmapButton( this, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	gSizer3->Add( bottomleft, 0, wxALL, 5 );
	
	bottommid = new wxBitmapButton( this, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	gSizer3->Add( bottommid, 0, wxALL, 5 );
	
	bottomright = new wxBitmapButton( this, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	gSizer3->Add( bottomright, 0, wxALL, 5 );
	
	fgSizer1->Add( gSizer3, 1, wxEXPAND, 5 );
	
	
	fgSizer1->Add( 140, 100, 1, wxEXPAND, 5 );
	
	wxGridSizer* gSizer4;
	gSizer4 = new wxGridSizer( 0, 2, 0, 0 );
	
	m_button26 = new wxButton( this, wxID_ANY, wxT("Reset"), wxDefaultPosition, wxDefaultSize, 0 );
	gSizer4->Add( m_button26, 0, wxALL, 5 );
	
	m_button27 = new wxButton( this, wxID_ANY, wxT("Exit"), wxDefaultPosition, wxDefaultSize, 0 );
	gSizer4->Add( m_button27, 0, wxALL, 5 );
	
	fgSizer1->Add( gSizer4, 1, wxEXPAND, 5 );
	
	this->SetSizer( fgSizer1 );
	this->Layout();
	statusbar = this->CreateStatusBar( 1, wxST_SIZEGRIP, wxID_ANY );
	menubar = new wxMenuBar( 0 );
	filemenu = new wxMenu();
	wxMenuItem* exit;
	exit = new wxMenuItem( filemenu, wxID_ANY, wxString( wxT("Exit") ) + wxT('\t') + wxT("ALT-F4"), wxEmptyString, wxITEM_NORMAL );
	filemenu->Append( exit );
	
	menubar->Append( filemenu, wxT("File") ); 
	
	this->SetMenuBar( menubar );
	
	
	this->Centre( wxBOTH );
	
	// Connect Events
	topleft->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIClass::ButtonPress ), NULL, this );
	topmid->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIClass::ButtonPress ), NULL, this );
	topright->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIClass::ButtonPress ), NULL, this );
	midleft->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIClass::ButtonPress ), NULL, this );
	midmid->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIClass::ButtonPress ), NULL, this );
	midright->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIClass::ButtonPress ), NULL, this );
	bottomleft->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIClass::ButtonPress ), NULL, this );
	bottommid->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIClass::ButtonPress ), NULL, this );
	bottomright->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIClass::ButtonPress ), NULL, this );
	m_button26->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIClass::ResetGame ), NULL, this );
	m_button27->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIClass::ExitProgram ), NULL, this );
	this->Connect( exit->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIClass::ExitProgram ) );
}

GUIClass::~GUIClass()
{
	// Disconnect Events
	topleft->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIClass::ButtonPress ), NULL, this );
	topmid->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIClass::ButtonPress ), NULL, this );
	topright->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIClass::ButtonPress ), NULL, this );
	midleft->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIClass::ButtonPress ), NULL, this );
	midmid->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIClass::ButtonPress ), NULL, this );
	midright->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIClass::ButtonPress ), NULL, this );
	bottomleft->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIClass::ButtonPress ), NULL, this );
	bottommid->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIClass::ButtonPress ), NULL, this );
	bottomright->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIClass::ButtonPress ), NULL, this );
	m_button26->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIClass::ResetGame ), NULL, this );
	m_button27->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIClass::ExitProgram ), NULL, this );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIClass::ExitProgram ) );
	
}

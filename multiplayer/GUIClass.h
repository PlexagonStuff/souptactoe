///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Jun 30 2011)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __GUICLASS_H__
#define __GUICLASS_H__

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/bmpbuttn.h>
#include <wx/string.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/button.h>
#include <wx/sizer.h>
#include <wx/statusbr.h>
#include <wx/menu.h>
#include <wx/frame.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class GUIClass
///////////////////////////////////////////////////////////////////////////////
class GUIClass : public wxFrame 
{
	private:
	
	protected:
		wxBitmapButton* topleft;
		wxBitmapButton* topmid;
		wxBitmapButton* topright;
		wxBitmapButton* midleft;
		wxBitmapButton* midmid;
		wxBitmapButton* midright;
		wxBitmapButton* bottomleft;
		wxBitmapButton* bottommid;
		wxBitmapButton* bottomright;
		wxButton* m_button26;
		wxButton* m_button27;
		wxStatusBar* statusbar;
		wxMenuBar* menubar;
		wxMenu* filemenu;
		
		// Virtual event handlers, overide them in your derived class
		virtual void ButtonPress( wxCommandEvent& event ) { event.Skip(); }
		virtual void ResetGame( wxCommandEvent& event ) { event.Skip(); }
		virtual void ExitProgram( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		GUIClass( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("soup-tac-toe"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 500,300 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );
		
		~GUIClass();
	
};

#endif //__GUICLASS_H__

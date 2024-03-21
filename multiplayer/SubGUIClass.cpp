#include "SubGUIClass.h"

SubGUIClass::SubGUIClass( wxWindow* parent )
:
GUIClass( parent )
{

}

void SubGUIClass::InitializeGame() {
	//I needed a public way to call the reset game event
	ResetGame(wxCommandEvent());
}

//https://codepen.io/garbot/pen/bWLGGL 
int SubGUIClass::board[9] = { 0,0,0,
							  0,0,0,
							  0,0,0 };

void SubGUIClass::ButtonPress( wxCommandEvent& event )
{
	wxBitmapButton* button = wxDynamicCast(event.GetEventObject(), wxBitmapButton);
	//wxMessageDialog hello(this, wxString::Format(wxT("%i"),button->GetId()), "Message box", wxOK);
	//hello.ShowModal();
	
	//This gets a unique identifier for the button
	int buttonId = event.GetId();
	//This converts the button id to it's corresponding spot on the board
	int buttonSlot = boardPos.at(buttonId);

	//This checks to see if the button is blank, if so, switch the text to the current team and update board state
	if (board[buttonSlot] == none) {
		button->SetLabel(wxString::Format(wxT("%i"), currentTurn));
		if (currentTurn == broth) {
			button->SetBitmapLabel(scaleImage("images/broth_sauce.png"));
		}
		else {
			button->SetBitmapLabel(scaleImage("images/tomato_sauce.png"));
		}
		board[buttonSlot] = currentTurn;

		//Check for a win
		int winCheck = WinnerCheck();
		
		if (winCheck == none) {
			//Business as usual, keep playing

			wxString turnString;
			//Update whose turn it now is
			if (currentTurn == broth) {
				currentTurn = soup;
				turnString = "soup";
			}
			else {
				currentTurn = broth;
				turnString = "broth";
			}

			//Update the status bar
			wxStatusBar* status = findStatusBar();
			status->SetStatusText(turnString + "'s turn");
		}

		//Do winning stuff
		else {
			wxString winString;
			if (winCheck == broth) {
				winString = "Broth won!";
			}
			else if (winCheck == soup) {
				winString = "Soup won!";
			}
			else {
				winString = "It's a tie!";
			}
			wxMessageDialog hello(this, winString + " Play again?", "Message box", wxYES_NO);
			int tacos = hello.ShowModal();
			if (tacos == wxID_YES) {
				ResetGame(wxCommandEvent());
			}
			else {
				this->Close(true);
			}

		}


		

		
	}
	

	

}

void SubGUIClass::ResetGame( wxCommandEvent& event )
{
	//Reset the board state to all zeros
	int boardSize = sizeof(board) / sizeof(board[0]);
	for (int i = 0; i < boardSize; i++) {
		if (board[i] != 0) {
			board[i] = 0;
		}
	}

	//Reset the buttons
	wxWindowList windowChildren = this->GetChildren();

	wxWindowList::iterator iter;

	//return wxDynamicCast(*(windowChildren.end()), wxStatusBar);
	for (iter = windowChildren.begin(); iter != windowChildren.end(); ++iter) {
		wxBitmapButton* button = wxDynamicCast(*iter, wxBitmapButton);
		if (button) {
			button->SetBitmapLabel(scaleImage("images/empty_soup.png"));
		}
	}

	wxStatusBar* status = findStatusBar();
	status->SetStatusText("Broth's Turn!");
}

void SubGUIClass::ExitProgram( wxCommandEvent& event )
{
// TODO: Implement ExitProgram
	wxMessageDialog hello(this, "Are you sure?", "Message box", wxYES_NO);
	int tacos = hello.ShowModal();
	if (tacos == wxID_YES) {
		this->Close( true );
	}
	

}

int SubGUIClass::WinnerCheck() {
	//Logic taken from https://codepen.io/garbot/pen/bWLGGL, makes sense honestly

	//check for horizontal rows
	for (int i = 0; i <= 6; i += 3) {
		//This loop starts at the start of each row, and as such, we can just check the other members of the row.
		if (board[i] != 0 && board[i + 1] == board[i] && board[i + 1] == board[i + 2]) {
			return board[i];
		}
	}
	//check for vertical columns
	for (int i = 0; i <= 2; i += 1) {
		//This loop starts at the start of each row, and as such, we can just check the other members of the row.
		if (board[i] != 0 && board[i + 3] == board[i] && board[i + 3] == board[i + 6]) {
			return board[i];
		}
	}
	//check the diagonals
	if ((board[4] != 0) && ((board[4] == board[0] && board[4] == board[8]) || (board[4] == board[2] && board[4] == board[6]))) {
		return board[4];
	}
	if (emptySlots().size() == 0) {
		//We have tied, error code is 3
		return 3;
	}
	else {
		//The game is not over yet, so keep playing. 0 = none;
		return 0;
	}
}

//Use for AI hopefully?
std::vector<int> SubGUIClass::emptySlots() {
	std::vector<int> slots;
	//Size of board[0] will be 4 bytes since int
	int boardSize = sizeof(board) / sizeof(board[0]);
	for (int i = 0; i < boardSize; i++) {
		if (board[i] == 0) {
			slots.push_back(i);
		}
	}
	return slots;
}

wxStatusBar* SubGUIClass::findStatusBar() {
	wxWindowList windowChildren = this->GetChildren();

	wxWindowList::iterator iter;

	//return wxDynamicCast(*(windowChildren.end()), wxStatusBar);
	for (iter = windowChildren.begin(); iter != windowChildren.end(); ++iter) {
		wxStatusBar* statusBar = wxDynamicCast(*iter, wxStatusBar);
		if (statusBar) {
			return statusBar;
		}
	}
	
	
	return NULL;
}

wxBitmap SubGUIClass::scaleImage(wxString path) {
	wxBitmap soup(wxT(path), wxBITMAP_TYPE_ANY);
	wxImage soupPNG = soup.ConvertToImage();
	soup = wxBitmap(soupPNG.Scale(40, 40));
	return soup;
}


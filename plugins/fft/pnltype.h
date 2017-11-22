#ifndef PNLTYPE_H
#define PNLTYPE_H

//(*Headers(pnlType)
#include <wx/panel.h>
#include "wmlist.h"
//*)

class FFTBuilder;

class pnlType: public wxPanel
{
	public:

		pnlType(wxWindow* parent,FFTBuilder* pBuilder, wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~pnlType();

		//(*Declarations(pnlType)
		wmList* m_plstFFT_Type;
		//*)

	protected:

		//(*Identifiers(pnlType)
		static const long ID_M_PLST6;
		//*)

	private:

		//(*Handlers(pnlType)
		void OnlstFFT_TypeSelected(wxCommandEvent& event);
		//*)

		FFTBuilder* m_pBuilder;
		DECLARE_EVENT_TABLE()
};

#endif

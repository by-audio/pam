#ifndef PNLSETTINGSNMOS_H
#define PNLSETTINGSNMOS_H

#ifdef __NMOS__
//(*Headers(pnlSettingsNmos)
#include "wmbutton.h"
#include <wx/panel.h>
//*)
#include "wmlist.h"
#include <memory>

class Sender;

class pnlSettingsNmos: public wxPanel
{
	public:

		pnlSettingsNmos(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize, long nStyle=0, const wxString& sId=wxEmptyString);
		virtual ~pnlSettingsNmos();

		//(*Declarations(pnlSettingsNmos)
		wmButton* m_pbtnClient;
		wmButton* m_pbtnNmos;
		//*)

		wmButton* m_pbtnConnection;

        void SetReceiverId(const wxString& sReceiverId)
        {
            m_sReceiverId = sReceiverId;
        }
        const wxString& GetReceiverId() const
        {
            return m_sReceiverId;
        }

        void SetSender(const wxString& sSenderId);

		void AddSender(std::shared_ptr<Sender> pSender);
		void UpdateSender(std::shared_ptr<Sender> pSender);
		void RemoveSenders();

		void SubscriptionRequest(const wxString& sReceiverId, const wxString& sResponse, unsigned long nResult);

	protected:

		//(*Identifiers(pnlSettingsNmos)
		static const long ID_M_PBTN22;
		static const long ID_M_PBTN1;
		//*)

	private:

		//(*Handlers(pnlSettingsNmos)
		void OnbtnNmosClick(wxCommandEvent& event);
		void OnbtnClientClick(wxCommandEvent& event);
		//*)

		void OnbtnConnectionClick(wxCommandEvent& event);
		void OnSenderSelected(wxCommandEvent& event);

		bool ConnectionIS04(size_t nSenderButton);
		bool ConnectionIS05(size_t nSenderButton);
		wmList* m_plstSenders;
        wxString m_sReceiverId;
		DECLARE_EVENT_TABLE()
};

#endif
#endif

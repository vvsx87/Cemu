#pragma once

#include <wx/app.h>

class MainWindow;

class CemuApp : public wxApp
{
public:
	bool OnInit() override;
	int OnExit() override;

	void OnAssertFailure(const wxChar* file, int line, const wxChar* func, const wxChar* cond, const wxChar* msg) override;
	int FilterEvent(wxEvent& event) override;

	std::vector<const wxLanguageInfo*> GetLanguages() const;

	static void CreateDefaultFiles(bool first_start = false);
	static bool TrySelectMLCPath(fs::path path);
	static bool SelectMLCPath(wxWindow* parent = nullptr);

private:
	void ActivateApp(wxActivateEvent& event);
	void LocalizeUI();
	static std::vector<const wxLanguageInfo*> GetAvailableTranslationLanguages(wxTranslations* translationsMgr);

	MainWindow* m_mainFrame = nullptr;

	wxLocale m_locale;
	std::vector<const wxLanguageInfo*> m_availableTranslations;
};

wxDECLARE_APP(CemuApp);

#include "Interface.hpp"


Interface::Interface(sf::RenderWindow& window, int& rodzajFraktala) : m_fractalType(rodzajFraktala), m_window(window){

	//	Okno przelaczania
	//-----------------------------------------------
	m_switchWindowFractal = sfg::Window::Create(2);
	m_switchBoxFractal = sfg::Box::Create(sfg::Box::Orientation::HORIZONTAL, 10.f);

	m_switchButtonKoch = sfg::Button::Create("Gwiazdka Kocha");
	m_switchButtonCarpet = sfg::Button::Create("Dywan Sierpinskiego");
	m_switchButtonJuli = sfg::Button::Create("Zbior Julii");
	m_switchButtonFern = sfg::Button::Create("Paproc Barnsleya");
	m_switchButtonMandel = sfg::Button::Create("Zbior Mandelbrota");
	m_switchButtonKantor = sfg::Button::Create("Zbior Cantora");
	m_switchButtonTriangle = sfg::Button::Create("Trojkat Sierpinskiego");

	m_switchBoxFractal->Pack(m_switchButtonKoch);
	m_switchBoxFractal->Pack(m_switchButtonCarpet);
	m_switchBoxFractal->Pack(m_switchButtonJuli);
	m_switchBoxFractal->Pack(m_switchButtonFern);
	m_switchBoxFractal->Pack(m_switchButtonMandel);
	m_switchBoxFractal->Pack(m_switchButtonKantor);
	m_switchBoxFractal->Pack(m_switchButtonTriangle);

	m_switchButtonKoch->GetSignal(sfg::Widget::OnLeftClick).Connect(std::bind(&Interface::buttonSwitchClick, this, kKoch));
	m_switchButtonCarpet->GetSignal(sfg::Widget::OnLeftClick).Connect(std::bind(&Interface::buttonSwitchClick, this, kSierpinskiCarpet));
	m_switchButtonJuli->GetSignal(sfg::Widget::OnLeftClick).Connect(std::bind(&Interface::buttonSwitchClick, this, kJuli));
	m_switchButtonFern->GetSignal(sfg::Widget::OnLeftClick).Connect(std::bind(&Interface::buttonSwitchClick, this, kFern));
	m_switchButtonMandel->GetSignal(sfg::Widget::OnLeftClick).Connect(std::bind(&Interface::buttonSwitchClick, this, kMandel));
	m_switchButtonKantor->GetSignal(sfg::Widget::OnLeftClick).Connect(std::bind(&Interface::buttonSwitchClick, this, kCantor));
	m_switchButtonTriangle->GetSignal(sfg::Widget::OnLeftClick).Connect(std::bind(&Interface::buttonSwitchClick, this, kTriangle));

	m_switchWindowFractal->Add(m_switchBoxFractal);

	//	Okno koch
	//-----------------------------------------------

	m_kochWindow = sfg::Window::Create();
	m_kochWindow->SetTitle("Ustawienia");
	m_kochBox = sfg::Box::Create(sfg::Box::Orientation::VERTICAL, 10.f);

	m_kochLabelIter = sfg::Label::Create("iteracja");
	m_kochButtonIter = sfg::SpinButton::Create(0.f, 10.f, 1.f);
	m_kochButtonIter->SetRequisition(sf::Vector2f(80.f, 0.f));
	m_kochButtonIter->SetDigits(0);

	m_kochBox->Pack(m_kochLabelIter);
	m_kochBox->Pack(m_kochButtonIter);
	m_kochWindow->Add(m_kochBox);

	m_kochWindow->SetPosition(sf::Vector2f(0, 200));
	m_kochWindow->Show(false);

	//	Okno carpet
	//-----------------------------------------------

	m_carpetWindow = sfg::Window::Create();
	m_carpetWindow->SetTitle("Ustawienia");
	m_carpetBox = sfg::Box::Create(sfg::Box::Orientation::VERTICAL, 10.f);

	m_carpetLabelIter = sfg::Label::Create("iteracja");
	int carpetMaxIter = floor((log(std::min(m_window.getSize().x, m_window.getSize().y)) / log(3)));
	m_carpetButtonIter = sfg::SpinButton::Create(0.f, carpetMaxIter, 1.f);
	m_carpetButtonIter->SetRequisition(sf::Vector2f(80.f, 0.f));
	m_carpetButtonIter->SetDigits(0);

	m_carpetBox->Pack(m_carpetLabelIter);
	m_carpetBox->Pack(m_carpetButtonIter);
	m_carpetWindow->Add(m_carpetBox);

	m_carpetWindow->SetPosition(sf::Vector2f(0, 200));
	m_carpetWindow->Show(false);

	//	Okno cantor
	//-----------------------------------------------

	m_cantorWindow = sfg::Window::Create();
	m_cantorWindow->SetTitle("Ustawienia");
	m_cantorBox = sfg::Box::Create(sfg::Box::Orientation::VERTICAL, 10.f);

	m_cantorLabelIter = sfg::Label::Create("iteracja");
	m_cantorButtonIter = sfg::SpinButton::Create(0.f, 10.f, 1.f);
	m_cantorButtonIter->SetRequisition(sf::Vector2f(80.f, 0.f));
	m_cantorButtonIter->SetDigits(0);

	m_cantorBox->Pack(m_cantorLabelIter);
	m_cantorBox->Pack(m_cantorButtonIter);
	m_cantorWindow->Add(m_cantorBox);

	m_cantorWindow->SetPosition(sf::Vector2f(0, 200));
	m_cantorWindow->Show(false);

	// Okno julia
	//-----------------------------------------------

	m_juliWindow = sfg::Window::Create();
	m_juliWindow->SetTitle("Ustawienia");
	m_juliBox = sfg::Box::Create(sfg::Box::Orientation::VERTICAL, 10.f);

	m_juliButtonCx = sfg::SpinButton::Create(-2.f, 2.f, 0.001f);
	m_juliButtonCy = sfg::SpinButton::Create(-2.f, 2.f, 0.001f);
	m_juliButtonIter = sfg::SpinButton::Create(5.f, 1000.f, 10.f);

	m_juliButtonIter->SetDigits(0);
	m_juliButtonCx->SetDigits(3);
	m_juliButtonCy->SetDigits(3);

	m_juliButtonIter->SetValue(500);
	m_juliButtonCx->SetValue(-0.75f);
	m_juliButtonCy->SetValue(0.11f);

	m_juliLabelIter = sfg::Label::Create("Ile iteracji");
	m_juliLabelCx = sfg::Label::Create("wartosc Cx");
	m_juliLabelCy = sfg::Label::Create("wartosc Cy");

	m_juliBox->Pack(m_juliLabelIter);
	m_juliBox->Pack(m_juliButtonIter);
	m_juliBox->Pack(m_juliLabelCx);
	m_juliBox->Pack(m_juliButtonCx);
	m_juliBox->Pack(m_juliLabelCy);
	m_juliBox->Pack(m_juliButtonCy);
	m_juliWindow->Add(m_juliBox);

	m_juliWindow->SetPosition(sf::Vector2f(0, 200));

	//	Okno mandelbrot
	//-----------------------------------------------

	m_mandelWindow = sfg::Window::Create();
	m_mandelWindow->SetTitle("Ustawienia");
	m_mandelBox = sfg::Box::Create(sfg::Box::Orientation::VERTICAL, 10.f);

	m_mandelLabelIter = sfg::Label::Create("Ile iteracji");
	m_mandelButtonIter = sfg::SpinButton::Create(5.f, 1000.f, 2.f);
	m_mandelButtonIter->SetRequisition(sf::Vector2f(80.f, 0.f));
	m_mandelButtonIter->SetDigits(0);
	m_mandelButtonIter->SetValue(50);

	m_mandelBox->Pack(m_mandelLabelIter);
	m_mandelBox->Pack(m_mandelButtonIter);
	m_mandelWindow->Add(m_mandelBox);

	m_mandelWindow->SetPosition(sf::Vector2f(0, 200));
	m_mandelWindow->Show(false);

	//-----------------------------------------------

	m_desktop.Add(m_carpetWindow);
	m_desktop.Add(m_mandelWindow);
	m_desktop.Add(m_juliWindow);
	m_desktop.Add(m_cantorWindow);
	m_desktop.Add(m_kochWindow);
	m_desktop.Add(m_switchWindowFractal);
	m_desktop.Update(0.f);
}

void Interface::buttonSwitchClick(int switchTo){
	showHideWindows(switchTo);
	m_fractalType = switchTo;
	m_window.clear(sf::Color::White);
}

void Interface::showHideWindows(int show){
	switch (m_fractalType){
	case kCantor:
		m_cantorWindow->Show(false);
		break;
	case kKoch:
		m_kochWindow->Show(false);
		break;
	case kJuli:
		m_juliWindow->Show(false);
		break;
	case kMandel:
		m_mandelWindow->Show(false);
		break;
	case kSierpinskiCarpet:
		m_carpetWindow->Show(false);
		break;
	}

	switch (show){
	case kCantor:
		m_cantorWindow->Show(true);
		break;
	case kKoch:
		m_kochWindow->Show(true);
		break;
	case kJuli:
		m_juliWindow->Show(true);
		break;
	case kMandel:
		m_mandelWindow->Show(true);
		break;
	case kSierpinskiCarpet:
		m_carpetWindow->Show(true);
		break;
	}
}

void Interface::update(sf::Clock& clock){
	if (clock.getElapsedTime().asMicroseconds() >= 5000) {
		// Update() takes the elapsed time in seconds.
		auto microseconds = clock.getElapsedTime().asMicroseconds();
		m_desktop.Update(static_cast<float>(microseconds) / 1000000.f);

		clock.restart();
	}
}

void Interface::handleEvent(sf::Event event){
	m_desktop.HandleEvent(event);
}

int Interface::kochGetIter(){
	return m_kochButtonIter->GetValue();
}

int Interface::cantorGetIter(){
	return m_cantorButtonIter->GetValue();
}

int Interface::juliGetIter(){
	return m_juliButtonIter->GetValue();
}

int Interface::mandelGetIter(){
	return m_mandelButtonIter->GetValue();
}

int Interface::carpetGetIter(){
	return m_carpetButtonIter->GetValue();
}

sf::Vector2f Interface::juliGetC(){
	return sf::Vector2f(m_juliButtonCx->GetValue(), m_juliButtonCy->GetValue());
}

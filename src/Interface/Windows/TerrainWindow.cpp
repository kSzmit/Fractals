#include "TerrainWindow.hpp"


TerrainWindow::TerrainWindow(){
	m_window = sfg::Window::Create();
	m_window->SetTitle("Ustawienia");
	m_box = sfg::Box::Create(sfg::Box::Orientation::VERTICAL, 10.f);

	m_generateButton = sfg::Button::Create("Generuj");

	m_box->Pack(m_generateButton);
	m_generateButton->GetSignal(sfg::Widget::OnLeftClick).Connect(std::bind(&TerrainWindow::setGenerate, this, true));

	m_window->Add(m_box);
	m_window->SetPosition(sf::Vector2f(0, 200));
	m_window->Show(false);
}

void TerrainWindow::setGenerate(bool generate){
	m_generate = generate;
}

bool TerrainWindow::checkGenerate(){
	if (m_generate){
		m_generate = false;
		return true;
	}
	return false;
}


void TerrainWindow::show(bool show){
	m_window->Show(show);
}

sfg::Window::Ptr TerrainWindow::getWindow(){
	return m_window;
}
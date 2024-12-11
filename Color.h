#ifndef COLOR_H
#define COLOR_H

#include <iostream>
#include <string>

namespace PlannerCLI {
	class Color
	{
	public:
		Color() {}
		Color(const std::string& background, const std::string& foreground) {}
		virtual ~Color(){}

		std::string GetBackgroundColor() const{
			return m_strBackground;
		}

		std::string GetForegroundColor() const {
			return m_strForeground;
		}

		void SetBackgroundColor(const std::string& ansiColor) {
			m_strBackground = ansiColor;
		}

		void SetForegroundColor(const std::string& ansiColor) {
			m_strForeground = ansiColor;
		}

		void Display() {
			std::cout << m_strBackground << m_strForeground;
		}

	private:
		std::string m_strBackground;
		std::string m_strForeground;
	};

}

#endif




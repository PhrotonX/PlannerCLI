#include "Time.h"

namespace PlannerCLI {
	Time::Time()
	{
		m_nHours = 0;
		m_nMinutes = 0;
	}

	Time::Time(const int& hours, const int& minutes) {
		m_nHours = hours;
		m_nMinutes = minutes;
	}

	Time::Time(const std::string strValue)
	{
		std::string strHour = strValue.substr(0, 2);
		std::string strMinute = strValue.substr(3, 4);

		SetHours(std::stoi(strHour));
		SetMinutes(std::stoi(strMinute));
	}

	std::string Time::GetString() const {
		return AddLeadingZero(m_nHours) + ":" + AddLeadingZero(m_nMinutes);
	}

	std::string Time::AddLeadingZero(int value)
	{
		std::string strValue = std::to_string(value);

		if (value < 10) {
			strValue = "0" + strValue;
		}

		return strValue;
	}

	bool Time::operator>(const Time& other){
		if (this->GetHours() > other.GetHours()) {
			return true;
		}else if (this->GetHours() == other.GetHours()) {
			if (this->GetMinutes() > other.GetMinutes()) {
				return true;
			}
		}

		return false;
	}

	bool Time::operator>=(const Time& other)
	{
		if (this->GetHours() >= other.GetHours()) {
			if (this->GetMinutes() >= other.GetMinutes()) {
				return true;
			}
		}

		return false;
	}

	bool Time::operator==(const Time& other)
	{
		if (this->GetHours() == other.GetHours()) {
			if (this->GetMinutes() == other.GetMinutes()) {
				return true;
			}
		}

		return false;
	}

	bool Time::operator!=(const Time& other)
	{
		if (this->GetHours() != other.GetHours()) {
			return true;
		}else if (this->GetMinutes() != other.GetMinutes()) {
			return true;
		}

		return false;
	}

	bool Time::operator<(const Time& other)
	{
		if (this->GetHours() < other.GetHours()) {
			return true;
		}
		else if (this->GetHours() == other.GetHours()) {
			if (this->GetMinutes() < other.GetMinutes()) {
				return true;
			}
		}

		return false;
	}
	bool Time::operator<=(const Time& other)
	{
		if (this->GetHours() <= other.GetHours()) {
			if (this->GetMinutes() <= other.GetMinutes()) {
				return true;
			}
		}

		return false;
	}
}
#ifndef EVENT_H
#define EVENT_H
#include "Model.h"
#include <string>
#include "Time.h"

namespace PlannerCLI {
	class Event
	{
	public:
		Event(){}
		virtual ~Event(){}
		//Reserved for To-Do list.
		/*
		void AddNote(const std::string& note) {
			if (m_nNoteCount >= 0 && m_nNoteCount < 2) {
				m_strNotes[m_nNoteCount] = note;
				m_nNoteCount++;
			}
		}*/

		std::string GetColor() const {
			return m_strColor;
		}

		std::string GetTitle() const {
			return m_strTitle;
		}

		std::string GetDescription() const {
			return m_strDescription;
		}

		std::string GetLocation() const{
			return m_strLocation;
		}

		/*
		std::string GetNote(int position) const {
			return m_strNotes[position];
		}*/

		void SetTitle(const std::string& value) {
			m_strTitle = value;
		}

		void SetDescription(const std::string& value) {
			m_strDescription = value;
		}

		void SetLocation(const std::string& value) {
			m_strLocation = value;
		}

		
	private:
		std::string m_strTitle;
		std::string m_strDescription;
		std::string m_strLocation;
		std::string m_strColor;
		Time m_timeBegin;
		Time m_timeEnd;

		std::string m_strNotes[3];
		int m_nNoteCount = 0;
	};
}

#endif //EVENT_H

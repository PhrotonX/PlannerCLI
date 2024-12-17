#ifndef EVENT_H
#define EVENT_H
#include "Model.h"
#include <string>
#include "Time.h"
#include "Color.h"
#include "Date.h"
#include "Nullable.h"

namespace PlannerCLI {
	class Event : public Nullable
	{
	public:
		inline static long EVENT_COUNT = 0;

		Event();
		virtual ~Event(){}
		//Reserved for To-Do list.
		/*
		void AddNote(const std::string& note) {
			if (m_nNoteCount >= 0 && m_nNoteCount < 2) {
				m_strNotes[m_nNoteCount] = note;
				m_nNoteCount++;
			}
		}*/

		Color GetColor() const {
			return m_color;
		}

		long GetID() const {
			return m_nId;
		}

		std::string GetTitle() const {
			return m_strTitle;
		}

		Time GetStartTime() const {
			return m_timeBegin;
		}

		Time GetEndTime() const {
			return m_timeEnd;
		}

		std::string GetDescription() const {
			return m_strDescription;
		}

		std::string GetLocation() const{
			return m_strLocation;
		}

		size_t GetPosition() const {
			return m_nPosition;
		}

		/**
			\remarks Used for search results.
		*/
		Date GetDate() const {
			return m_date;
		}

		/*
		std::string GetNote(int position) const {
			return m_strNotes[position];
		}*/

		void SetTitle(const std::string& value) {
			m_strTitle = value;
		}

		/**
			\remarks Used for search results.
		*/
		void SetDate(Date date) {
			m_date = date;
		}

		void SetDescription(const std::string& value) {
			m_strDescription = value;
		}

		void SetID(const int& value) {
			m_nId = value;
		}

		void SetLocation(const std::string& value) {
			m_strLocation = value;
		}

		void SetPosition(const size_t& position) {
			m_nPosition = position;
		}

		void SetStartTime(const Time& value) {
			m_timeBegin = value;
		}

		void SetEndTime(const Time& value) {
			m_timeEnd = value;
		}

		
	private:
		long m_nId;
		size_t m_nPosition;
		std::string m_strTitle;
		std::string m_strDescription;
		std::string m_strLocation;
		Date m_date;
		Color m_color;
		Time m_timeBegin;
		Time m_timeEnd;

		//std::string m_strNotes[3];
		//long m_nNoteCount = 0;
	};
}

#endif //EVENT_H

#pragma once
#include "Session.h"
#include "../dml/MessageManager.h"

namespace ki
{
namespace protocol
{
namespace net
{
	enum class InvalidDMLMessageErrorCode
	{
		INVALID_MESSAGE_DATA,
		INSUFFICIENT_ACCESS
	};

	/**
	 * Implements an application protocol that uses the DML
	 * message system (as seen in Wizard101 and Pirate101).
	 */
	class DMLSession : public virtual Session
	{
	public:
		DMLSession(uint16_t id, const dml::MessageManager &manager);
		virtual ~DMLSession() = default;

		const dml::MessageManager &get_manager() const;

		void send_message(const dml::Message &message);
	protected:
		void on_application_message(const PacketHeader& header) override;
		virtual void on_message(const dml::Message &message) {}
		virtual void on_invalid_message(InvalidDMLMessageErrorCode error) {}
	private:
		const dml::MessageManager &m_manager;
	};
}
}
}

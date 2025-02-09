/*
 * Copyright (c) 2015 Oleg Morozenkov
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#ifndef TGBOT_CPP_FORCEREPLY_H
#define TGBOT_CPP_FORCEREPLY_H

#include <memory>

#include "tgbot/types/GenericReply.h"

namespace TgBot {

/**
 * Upon receiving a message with this object, Telegram clients will display a reply interface to the user (act as if the user has selected the bot‘s message and tapped ’Reply'). This can be extremely useful if you want to create user-friendly step-by-step interfaces without having to sacrifice privacy mode.
 * Example: A poll bot for groups runs in privacy mode (only receives commands, replies to its messages and mentions). There could be two ways to create a new poll:
 * Explain the user how to send a command with parameters (e.g. /newpoll question answer1 answer2). May be appealing for hardcore users but lacks modern day polish.
 * Guide the user through a step-by-step process. ‘Please send me your question’, ‘Cool, now let’s add the first answer option‘, ’Great. Keep adding answer options, then send /done when you‘re ready’.
 * The last option is definitely more attractive. And if you use ForceReply in your bot‘s questions, it will receive the user’s answers even if it only receives replies, commands and mentions — without any extra work for the user.
 * @ingroup types
 */
class ForceReply : public GenericReply {

public:
	typedef std::shared_ptr<ForceReply> Ptr;

	/**
	 * Shows reply interface to the user, as if they manually selected the bot‘s message and tapped ’Reply'
	 */
	const bool forceReply = true;

	/**
	 * Optional. Use this parameter if you want to force reply from specific users only. Targets: 1) users that are @mentioned in the text of the Message object; 2) if the bot's message is a reply (has reply_to_message_id), sender of the original message.
	 */
	bool selective;
};

}

#endif //TGBOT_CPP_FORCEREPLY_H

/*
 * Copyright 2015 Aldebaran
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
*/

#ifndef MEMORY_STRING_CONVERTER_HPP
#define MEMORY_STRING_CONVERTER_HPP

/*
* LOCAL includes
*/
#include "../converter_base.hpp"
#include <naoqi_driver/message_actions.h>
#include <naoqi_driver/helpers.hpp>

/*
* ROS includes
*/
#include <naoqi_bridge_msgs/msg/StringStamped.h>

namespace naoqi
{
namespace converter
{

class MemoryStringConverter : public BaseConverter<MemoryStringConverter>
{
  typedef boost::function<void(naoqi_bridge_msgs::msg::StringStamped&)> Callback_t;

public:

  MemoryStringConverter( const std::string& name, const float& frequency, const qi::SessionPtr& session, const std::string& memory_key );

  void reset();

  void registerCallback( const message_actions::MessageAction action, Callback_t cb );

  void callAll( const std::vector<message_actions::MessageAction>& actions );

private:
  bool convert();

private:
  /** Memory key to retrieve data */
  std::string memory_key_;
  /** Memory (Proxy) configurations */
  qi::AnyObject p_memory_;

  std::map<message_actions::MessageAction, Callback_t> callbacks_;
  naoqi_bridge_msgs::msg::StringStamped msg_;

}; // class

} //publisher
} // naoqi

#endif

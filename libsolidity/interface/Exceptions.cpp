/*
	This file is part of solidity.

	solidity is free software: you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation, either version 3 of the License, or
	(at your option) any later version.

	solidity is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with solidity.  If not, see <http://www.gnu.org/licenses/>.
*/
/**
 * @author Liana <liana@ethdev.com>
 * @date 2015
 * Solidity exception hierarchy.
 */

#include <libsolidity/interface/Exceptions.h>
#include <libsolidity/interface/Utils.h>

using namespace std;
using namespace dev;
using namespace dev::solidity;

Error::Error(Type _type): m_type(_type)
{
	switch(m_type)
	{
	case Type::DeclarationError:
		m_typeName = "Declaration Error";
		break;
	case Type::DocstringParsingError:
		m_typeName = "Docstring Parsing Error";
		break;
	case Type::ParserError:
		m_typeName = "Parser Error";
		break;
	case Type::SyntaxError:
		m_typeName = "Syntax Error";
		break;
	case Type::TypeError:
		m_typeName = "Type Error";
		break;
	case Type::Why3TranslatorError:
		m_typeName = "Why3 Translator Error";
		break;
	case Type::Warning:
		m_typeName = "Warning";
		break;
	default:
		solAssert(false, "");
		break;
	}
}

string Exception::lineInfo() const
{
	char const* const* file = boost::get_error_info<boost::throw_file>(*this);
	int const* line = boost::get_error_info<boost::throw_line>(*this);
	string ret;
	if (file)
		ret += *file;
	ret += ':';
	if (line)
		ret += boost::lexical_cast<string>(*line);
	return ret;
}

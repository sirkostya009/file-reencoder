#pragma once

namespace app {

	using namespace System;

	ref class Converter {
	public:
		array<unsigned char>^ toUtf8(String^ str) {
			return System::Text::Encoding::UTF8->GetBytes(str);
		}

		array<wchar_t>^ toUtf16(String^ str) {
			return str->ToCharArray();
		}

		array<unsigned char>^ toUtf32(String^ str) {
			return System::Text::Encoding::UTF32->GetBytes(str);
		}

		String^ toBinary(String^ str) {
			auto bytes = System::Text::Encoding::Default->GetBytes(str);
			auto sb = gcnew System::Text::StringBuilder();
			for (int i = 0; i < bytes->Length; i++) {
				sb->Append(Convert::ToString(bytes[i], 2));
			}
			return sb->ToString();
		}
	};

}

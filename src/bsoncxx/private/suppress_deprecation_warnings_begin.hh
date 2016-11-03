// Copyright 2016 MongoDB Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
// http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

// This header is intended to be included in source code in conjunction with
// suppress_deprecation_warnings_end.hh to disable deprecation warnings for a given section of code.
// Example usage:
//
//     {
//         some_function();
//     #include <path/to/suppress_deprecation_warnings_begin.hh>
//         some_deprecated_function();
//     #include <path/to/suppress_deprecation_warnings_end.hh>
//         some_other_function();
//     }
//
// suppress_deprecation_warnings_end.hh can only be included if it follows an include of
// suppress_deprecation_warnings_begin.hh. Otherwise, the pop_macro() pragma in the former file will
// generate a warning.

#pragma push_macro("BSONCXX_SUPPRESS_DEPRECATION_WARNINGS")

#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdeprecated-declarations"
#elif defined __GNUC__
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"
#elif defined _MSC_VER
#pragma warning(push)
#pragma warning(disable : 4996)
#endif

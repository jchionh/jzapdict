#include <iostream>
#include <string>
#include <algorithm>
#include <aws/lambda-runtime/runtime.h>

#include "WordDict.h"
#include "json.hpp"

using namespace aws::lambda_runtime;

invocation_response JzapWordQueryHandler(invocation_request const& request)
{
    // extract our query word
    auto payload = json::JSON::Load(request.payload);
    std::string wordQuery = payload["word"].ToString();

    // change to lowercase
    std::transform(wordQuery.begin(), wordQuery.end(), wordQuery.begin(), ::tolower);

    // query to find the word in our dict
    const bool wordFound = !(WordDict::SOWPODS_3_5.find(wordQuery) == WordDict::SOWPODS_3_5.end());
    const std::string&& queryResult = wordFound ? "true" : "false";

    std::cout << "Word: " << wordQuery << ", found? " << queryResult << std::endl;

    std::string resultString("{ \"result\": ");
    resultString += queryResult;
    resultString += " }";

    return invocation_response::success(resultString, "application/json");
}

int main()
{
    run_handler(JzapWordQueryHandler);
    return 0;
}

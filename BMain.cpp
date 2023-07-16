/* Copyright (c) 2012-2017 The ANTLR Project. All rights reserved.
 * Use of this file is governed by the BSD 3-clause license that
 * can be found in the LICENSE.txt file in the project root.
 */

//
//  main.cpp
//  antlr4-cpp-demo
//
//  Created by Mike Lischke on 13.03.16.
//

#include <fstream>
#include <iostream>
#include <ostream>

#include "LLVMIRLexer.h"
#include "LLVMIRParser.h"
#include "LLVMIRVisitor.h"
#include "antlr4-runtime.h"
#include "tree/AbstractParseTreeVisitor.h"
#include "tree/ParseTree.h"

#include "R5Logger.h"
#include "R5VisitorGenIRTree.h"

using namespace antlrcpp;
using namespace antlr4;
using std::cout;
using std::endl;
using tree::ErrorNode;
using tree::ParseTree;
using tree::TerminalNode;

int main(int argc, const char** argv)
{
    std::string inputFileName;
    std::string outputFileName;
    std::string optimizationLevel;

    if (!inputFileName.empty()) { LOGD("input: " << inputFileName); }

    // 处理缺省参数
    if (inputFileName.empty()) { inputFileName = "../testsrc/1.ll"; }
    if (outputFileName.empty()) { outputFileName = "../testsrc/1.s"; }
    std::ifstream inputStream;
    std::ofstream outputStream;

    auto sourceFileName = inputFileName;

    outputStream.open(outputFileName, std::ios::out);
    inputStream.open(sourceFileName, std::ios::in);
    if (!inputStream) {
        LOGE("File Open Error." << inputFileName);
        return 0;
    }
    LOGD("File Fine." << inputFileName);


    ANTLRInputStream input(inputStream);
    LLVMIRLexer lexer(&input);
    CommonTokenStream tokens(&lexer);
    LLVMIRParser parser(&tokens);
    tree::ParseTree* tree = parser.compilationUnit();
    auto visitor = new R5BE::R5VisitorGenIRTree();
    tree->accept(visitor);

    outputStream.close();
    return 0;
}

/*******************************************************************************
The content of the files in this repository include portions of the
AUDIOKINETIC Wwise Technology released in source code form as part of the SDK
package.

Commercial License Usage

Licensees holding valid commercial licenses to the AUDIOKINETIC Wwise Technology
may use these files in accordance with the end user license agreement provided
with the software or, alternatively, in accordance with the terms contained in a
written agreement between you and Audiokinetic Inc.

Copyright (c) 2021 Audiokinetic Inc.
*******************************************************************************/

#pragma once
#include "WwiseItemType.h"
#include "FastXml.h"

class WorkUnitXmlVisitor;

class WwiseProjectParser : public IFastXmlCallback
{
public:
	WwiseProjectParser(WorkUnitXmlVisitor* vis);
	virtual ~WwiseProjectParser() {};

private:
	FString currentPhysicalPath;
	FString workUnitName;
	FGuid currentId;
	bool inPhysicalFolder;
	bool inWorkUnit;
	WorkUnitXmlVisitor* visitor;

	bool ProcessXmlDeclaration(const TCHAR* ElementData, int32 XmlFileLineNumber) override;

	bool ProcessElement(const TCHAR* ElementName, const TCHAR* ElementData, int32 XmlFileLineNumber) override;

	bool ProcessAttribute(const TCHAR* AttributeName, const TCHAR* AttributeValue) override;

	bool ProcessClose(const TCHAR* ElementName) override;

	bool ProcessComment(const TCHAR* Comment) override;
};
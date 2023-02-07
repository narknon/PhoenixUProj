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

#include "Containers/UnrealString.h"
#include "WwiseItemType.h"
#include "WwiseWorkUnitParser.h"

class WorkUnitXmlVisitor
{
public:

	WorkUnitXmlVisitor() {}
	virtual ~WorkUnitXmlVisitor() {}

	virtual void Init( EWwiseItemType::Type Type) {}
	virtual void ForceInit() {}
	virtual void OnBeginParse() {}
	virtual void OnBeginPhysicalFolderParse() {}

	virtual void EnterWorkUnit(const WwiseWorkUnitParser::WorkUnitInfo & wwuInfo,  const FString& RelativePath,  EWwiseItemType::Type ItemType) {}
	virtual void ExitWorkUnit(bool IsStandaloneWorkUnit) {}

	// todo slaptiste: consider changing these functions to accept FGuids as arguments
	virtual void EnterEvent(const FGuid& Id, const FString& Name, const FString& RelativePath) {}

	virtual void EnterAcousticTexture(const FGuid& Id, const class FXmlNode* CurrentNode, const FString& Name, const FString& RelativePath) {}

	virtual void EnterAuxBus(const FGuid& Id, const FString& Name, const FString& RelativePath) {}
	virtual void ExitAuxBus() {}

	virtual void EnterFolderOrBus(const FGuid& Id, const FString& Name, const FString& RelativePath,  EWwiseItemType::Type ItemType) {}
	virtual void ExitFolderOrBus() {}

	virtual void EnterStateGroup(const FGuid& Id, const FString& Name, const FString& RelativePath) {}
	virtual void ExitStateGroup() {}

	virtual void EnterState(const FGuid& Id, const FString& Name, const FString& RelativePath) {}

	virtual void EnterSwitchGroup(const FGuid& Id, const FString& Name, const FString& RelativePath) {}
	virtual void ExitSwitchGroup() {}

	virtual void EnterSwitch(const FGuid& Id, const FString& Name, const FString& RelativePath) {}

	virtual void EnterGameParameter(const FGuid& Id, const FString& Name, const FString& RelativePath) {}

	virtual void EnterTrigger(const FGuid& Id, const FString& Name, const FString& RelativePath) {}

	virtual void ExitChildrenList() {}

	virtual void RemoveWorkUnit(const FString& WorkUnitPath) {}
	
	virtual FString FindRelativePath(const FString& WorkUnitPath, const FGuid& id, EWwiseItemType::Type ItemType) { return {}; };

	virtual void End() {}
	virtual void EndPhysicalFolderParse() {}

	virtual void RegisterError(const FString& xmlFilePath, const FString& errorMessage) {};
};

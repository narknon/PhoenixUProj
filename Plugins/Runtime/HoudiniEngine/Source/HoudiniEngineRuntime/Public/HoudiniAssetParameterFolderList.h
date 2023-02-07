#pragma once
#include "CoreMinimal.h"
#include "HoudiniAssetParameter.h"
#include "HoudiniAssetParameterFolderList.generated.h"

UCLASS(Blueprintable)
class HOUDINIENGINERUNTIME_API UHoudiniAssetParameterFolderList : public UHoudiniAssetParameter {
    GENERATED_BODY()
public:
    UHoudiniAssetParameterFolderList();
};


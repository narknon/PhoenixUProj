#pragma once
#include "CoreMinimal.h"
#include "BoneListSpawnInfo.h"
#include "EBoneTargetType.h"
#include "MultiFX2_NiagraBoneListSpawnInfo.h"
#include "MultiFX2_NiagraBoneListSpawnInfoByType.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UMultiFX2_NiagraBoneListSpawnInfoByType : public UMultiFX2_NiagraBoneListSpawnInfo {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<EBoneTargetType, FBoneListSpawnInfo> TypeMap;
    
    UMultiFX2_NiagraBoneListSpawnInfoByType();
};


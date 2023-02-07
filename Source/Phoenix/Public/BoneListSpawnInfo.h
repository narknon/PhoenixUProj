#pragma once
#include "CoreMinimal.h"
#include "BoneListSpawnInfo.generated.h"

USTRUCT(BlueprintType)
struct FBoneListSpawnInfo {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FName> BoneList;
    
    PHOENIX_API FBoneListSpawnInfo();
};


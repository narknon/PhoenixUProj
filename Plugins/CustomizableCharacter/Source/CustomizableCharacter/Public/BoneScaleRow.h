#pragma once
#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "BoneScaleEntry.h"
#include "BoneScaleRow.generated.h"

class USkeleton;

USTRUCT(BlueprintType)
struct FBoneScaleRow : public FTableRowBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<USkeleton> Skeleton;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FBoneScaleEntry> BoneScaleEntries;
    
    CUSTOMIZABLECHARACTER_API FBoneScaleRow();
};


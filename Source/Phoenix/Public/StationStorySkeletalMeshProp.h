#pragma once
#include "CoreMinimal.h"
#include "StationStoryProp.h"
#include "StationStorySkeletalMeshProp.generated.h"

class USkeletalMesh;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UStationStorySkeletalMeshProp : public UStationStoryProp {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USkeletalMesh* SkeletalMesh;
    
    UStationStorySkeletalMeshProp();
};


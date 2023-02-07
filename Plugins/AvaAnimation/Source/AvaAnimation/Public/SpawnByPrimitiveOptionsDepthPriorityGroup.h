#pragma once
#include "CoreMinimal.h"
#include "Engine/EngineTypes.h"
#include "SpawnByPrimitiveOptions.h"
#include "SpawnByPrimitiveOptionsDepthPriorityGroup.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class USpawnByPrimitiveOptionsDepthPriorityGroup : public USpawnByPrimitiveOptions {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TEnumAsByte<ESceneDepthPriorityGroup> DepthPriorityGroup;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TEnumAsByte<ESceneDepthPriorityGroup> ViewOwnerDepthPriorityGroup;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUseViewOwnerDepthPriorityGroup;
    
    USpawnByPrimitiveOptionsDepthPriorityGroup();
};


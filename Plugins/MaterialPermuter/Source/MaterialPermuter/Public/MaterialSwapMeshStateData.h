#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "MaterialSwapMeshStateData.generated.h"

UCLASS(Abstract, Blueprintable, Transient)
class MATERIALPERMUTER_API UMaterialSwapMeshStateData : public UObject {
    GENERATED_BODY()
public:
    UMaterialSwapMeshStateData();
};


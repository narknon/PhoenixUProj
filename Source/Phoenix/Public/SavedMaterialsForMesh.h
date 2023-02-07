#pragma once
#include "CoreMinimal.h"
#include "SavedMaterialsForMesh.generated.h"

class UMaterialInterface;

USTRUCT(BlueprintType)
struct FSavedMaterialsForMesh {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TWeakObjectPtr<UMaterialInterface>> SavedMaterialArray;
    
    PHOENIX_API FSavedMaterialsForMesh();
};


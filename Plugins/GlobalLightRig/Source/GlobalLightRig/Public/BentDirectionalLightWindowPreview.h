#pragma once
#include "CoreMinimal.h"
#include "BentDirectionalLightWindowPreview.generated.h"

class UStaticMeshComponent;

USTRUCT(BlueprintType)
struct FBentDirectionalLightWindowPreview {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UStaticMeshComponent* PaneComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UStaticMeshComponent*> DirectionComponents;
    
    GLOBALLIGHTRIG_API FBentDirectionalLightWindowPreview();
};


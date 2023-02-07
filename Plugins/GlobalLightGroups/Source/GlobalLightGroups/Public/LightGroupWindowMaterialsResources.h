#pragma once
#include "CoreMinimal.h"
#include "LightGroupWindowMaterialsResources.generated.h"

class UMaterialInstanceDynamic;

USTRUCT(BlueprintType)
struct GLOBALLIGHTGROUPS_API FLightGroupWindowMaterialsResources {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UMaterialInstanceDynamic*> SwappedMaterials;
    
    FLightGroupWindowMaterialsResources();
};


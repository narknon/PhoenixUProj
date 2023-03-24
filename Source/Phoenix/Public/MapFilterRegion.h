#pragma once
#include "CoreMinimal.h"
#include "Engine/DecalActor.h"
#include "MapFilterRegion.generated.h"

class UMaterialInterface;
class UTexture2D;

UCLASS(Blueprintable)
class AMapFilterRegion : public ADecalActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMaterialInterface* Material;
    
    AMapFilterRegion(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    void SetTexture(UTexture2D* inTexture);
    
    UFUNCTION(BlueprintCallable)
    FString GetName();
    
};


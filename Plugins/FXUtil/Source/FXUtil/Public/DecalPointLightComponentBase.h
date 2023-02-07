#pragma once
#include "CoreMinimal.h"
#include "Components/DecalComponent.h"
#include "DecalPointLightComponentBase.generated.h"

class UMaterialInstanceDynamic;
class UMaterialInterface;

UCLASS(Abstract, Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class FXUTIL_API UDecalPointLightComponentBase : public UDecalComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMaterialInterface* InverseSquaredDecalMaterial;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMaterialInterface* FalloffExponentDecalMaterial;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UMaterialInstanceDynamic* DecalMID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UMaterialInterface* DecalMIDParent;
    
public:
    UDecalPointLightComponentBase();
    UFUNCTION(BlueprintCallable)
    void UpdateDecal();
    
    UFUNCTION(BlueprintCallable)
    void SetInverseSquaredDecalMaterial(UMaterialInterface* NewInverseSquaredDecalMaterial);
    
    UFUNCTION(BlueprintCallable)
    void SetFalloffExponentDecalMaterial(UMaterialInterface* NewFalloffExponentDecalMaterial);
    
};


#pragma once
#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "ESanctuaryIdentity.h"
#include "SanctuaryPortalIdentityMaterialOverrideSettings.h"
#include "SanctuaryPortalMaterialSettings.h"
#include "SanctuaryPortalMaterialComponent.generated.h"

class UMaterialInstanceDynamic;
class UObject;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class USanctuaryPortalMaterialComponent : public USceneComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName EntranceZone;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSanctuaryPortalMaterialSettings MaterialSettings;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<ESanctuaryIdentity, FSanctuaryPortalIdentityMaterialOverrideSettings> IdentityOverrides;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bSeparateSettingsForPreRenderedCubemap;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSanctuaryPortalMaterialSettings PreRenderedCubemapMaterialSettings;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<ESanctuaryIdentity, FSanctuaryPortalIdentityMaterialOverrideSettings> PreRenderedCubemapIdentityOverrides;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<UMaterialInstanceDynamic*> MaterialInstances;
    
public:
    USanctuaryPortalMaterialComponent();
private:
    UFUNCTION(BlueprintCallable)
    void OnUpdateIdentity(ESanctuaryIdentity PreviousIdentity, ESanctuaryIdentity CurrentIdentity, float BlendWeight);
    
    UFUNCTION(BlueprintCallable)
    void OnUpdateEntranceMaterials(const UObject* InCaller);
    
};


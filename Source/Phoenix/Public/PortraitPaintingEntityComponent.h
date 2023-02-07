#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Components/ActorComponent.h"
#include "PortraitPaintingComponentStates.h"
#include "PortraitPaintingEntityComponent.generated.h"

class AActor;
class APortraitPaintingActor;
class UMaterialPermuterLoadingBundle;
class UMaterialSwap;
class UPortraitPaintingProp;
class USceneComponent;
class UScheduledEntity;

UCLASS(Blueprintable, Transient, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UPortraitPaintingEntityComponent : public UActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TWeakObjectPtr<APortraitPaintingActor>> PortraitActors;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<APortraitPaintingActor> InPortrait;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UPortraitPaintingProp*> Props;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UMaterialPermuterLoadingBundle* MaterialBundle;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UMaterialSwap* MaterialSwap;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTransform OriginalTransform;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FPortraitPaintingComponentStates ComponentStates;
    
    UPROPERTY(EditAnywhere, Export, Transient, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<USceneComponent> AttachedTo;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    uint8 bOverrodeMeshStates: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    uint8 bOverrodeMovementMode: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    uint8 bNudgedAudio: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    uint8 bNudgedCognitionStimuliSourceComponent: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    uint8 bAddedDoNotInvestigate: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    uint8 bAddedNoWeatherSwap: 1;
    
    UPortraitPaintingEntityComponent();
protected:
    UFUNCTION(BlueprintCallable)
    void OnFleshDestroyed(AActor* Actor, UScheduledEntity* entity);
    
    UFUNCTION(BlueprintCallable)
    void OnCharacterAddOnMeshesChanged(AActor* Actor);
    
};


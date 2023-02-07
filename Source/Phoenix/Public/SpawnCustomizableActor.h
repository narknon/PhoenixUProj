#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "Engine/EngineTypes.h"
#include "CustomizableActorLoadedOutputPinDelegate.h"
#include "Templates/SubclassOf.h"
#include "SpawnCustomizableActor.generated.h"

class AActor;
class ACustomizableActor;
class APawn;
class UObject;
class USpawnCustomizableActor;

UCLASS(Blueprintable)
class PHOENIX_API USpawnCustomizableActor : public UBlueprintAsyncActionBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FCustomizableActorLoadedOutputPin Loaded;
    
    USpawnCustomizableActor();
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static USpawnCustomizableActor* SpawnCustomizableActor(UObject* WorldContextObject, TSubclassOf<ACustomizableActor> Class, const FName RegistryId, const FTransform& Transform, AActor* Owner, APawn* Instigator, ESpawnActorCollisionHandlingMethod CollisionHandlingOverride);
    
private:
    UFUNCTION(BlueprintCallable)
    void OnFinishLoading(AActor* InOwner);
    
};


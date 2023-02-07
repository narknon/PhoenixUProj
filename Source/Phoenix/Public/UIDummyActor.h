#pragma once
#include "CoreMinimal.h"
#include "AnimationArchitect_Character.h"
#include "LODBudgeterInterface.h"
#include "DummyMeshLoadCompleteEventDelegate.h"
#include "UIDummyActor.generated.h"

class UObjectStateComponent;

UCLASS(Blueprintable)
class PHOENIX_API AUIDummyActor : public AAnimationArchitect_Character, public ILODBudgeterInterface {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UObjectStateComponent* ObjectStateComponent;
    
    UPROPERTY(BlueprintAssignable, BlueprintCallable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDummyMeshLoadCompleteEvent OnDummyMeshLoadComplete;
    
    UPROPERTY(BlueprintAssignable, BlueprintCallable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDummyMeshLoadCompleteEvent OnDummyGearLoadComplete;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool DesiredVisibility;
    
    AUIDummyActor();
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ShowDummy();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void HideDummy();
    
    
    // Fix for true pure virtual functions not being implemented
};


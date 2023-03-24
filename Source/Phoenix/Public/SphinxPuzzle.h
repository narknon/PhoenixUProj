#pragma once
#include "CoreMinimal.h"
#include "EInteractiveState.h"
#include "WorldObject.h"
#include "SphinxPuzzle.generated.h"

class AActor;
class UInteractiveObjectComponent;

UCLASS(Blueprintable)
class ASphinxPuzzle : public AWorldObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UInteractiveObjectComponent* InteractiveObjectComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString GuidString;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString PuzzleTypeName;
    
    ASphinxPuzzle(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void NotifyBeginPuzzle(EInteractiveState State);
    
    UFUNCTION(BlueprintCallable)
    void CleanUpObject(AActor* actorToDestroy);
    
};


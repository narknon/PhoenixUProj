#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "NPC_Volume.generated.h"

class UShapeComponent;

UCLASS(Abstract, Blueprintable, MinimalAPI)
class ANPC_Volume : public AActor {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UShapeComponent* CollisionComponent;
    
public:
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    TSet<TWeakObjectPtr<AActor>> EnteredList;
    
    ANPC_Volume(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    void SetActive(bool bInActive);
    
    UFUNCTION(BlueprintCallable)
    void OnEndOverlap(AActor* SelfActor, AActor* OtherActor);
    
    UFUNCTION(BlueprintCallable)
    void OnBeginOverlap(AActor* SelfActor, AActor* OtherActor);
    
    UFUNCTION(BlueprintCallable)
    bool GetActive();
    
};


#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "HideTransfigurationObjectActor.generated.h"

class UBoxComponent;

UCLASS(Blueprintable)
class AHideTransfigurationObjectActor : public AActor {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UBoxComponent* BoxComponent;
    
public:
    AHideTransfigurationObjectActor();
protected:
    UFUNCTION(BlueprintCallable)
    void OnOverlapEnd(AActor* OverlappedActor, AActor* OtherActor);
    
};


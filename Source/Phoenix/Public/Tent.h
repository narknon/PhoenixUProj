#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Tent.generated.h"

UCLASS(Blueprintable)
class ATent : public AActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 PropIndex;
    
    ATent(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SetTentMesh();
    
};


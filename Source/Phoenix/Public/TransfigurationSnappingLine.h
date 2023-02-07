#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TransfigurationSnappingLine.generated.h"

UCLASS(Blueprintable)
class ATransfigurationSnappingLine : public AActor {
    GENERATED_BODY()
public:
    ATransfigurationSnappingLine();
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void SetLineLength(float Length);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void FadeOutAndDestroy();
    
};


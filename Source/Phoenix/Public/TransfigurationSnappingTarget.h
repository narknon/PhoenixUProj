#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GameFramework/Actor.h"
#include "TransfigurationSnappingTarget.generated.h"

class UConjurationSnappingComponentBase;

UCLASS(Blueprintable)
class ATransfigurationSnappingTarget : public AActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UConjurationSnappingComponentBase* TargetObject;
    
    ATransfigurationSnappingTarget();
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void ShowBeamAtLocalLocation(const FVector& InLocationLocal);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void SetTargetObject(UConjurationSnappingComponentBase* SnappingTarget);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void FadeOutAndDestroy();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void ClearLitBeams();
    
};


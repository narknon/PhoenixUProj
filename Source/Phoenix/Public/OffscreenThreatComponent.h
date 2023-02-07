#pragma once
#include "CoreMinimal.h"
#include "Components/WidgetComponent.h"
#include "EEnemy_AttackThreatState.h"
#include "OffscreenThreatComponent.generated.h"

UCLASS(Blueprintable, EditInlineNew, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UOffscreenThreatComponent : public UWidgetComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 PointerIndex;
    
    UOffscreenThreatComponent();
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SetAttackState(EEnemy_AttackThreatState AttackState);
    
};


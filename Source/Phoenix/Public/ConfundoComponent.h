#pragma once
#include "CoreMinimal.h"
#include "ConfundoData.h"
#include "StateEffectComponent.h"
#include "ConfundoComponent.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UConfundoComponent : public UStateEffectComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FConfundoData ConfundoData;
    
    UConfundoComponent();
};


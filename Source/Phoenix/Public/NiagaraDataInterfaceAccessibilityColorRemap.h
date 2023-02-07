#pragma once
#include "CoreMinimal.h"
#include "NiagaraDataInterface.h"
#include "NiagaraDataInterfaceAccessibilityColorRemap.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UNiagaraDataInterfaceAccessibilityColorRemap : public UNiagaraDataInterface {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName ColorTableTag;
    
    UNiagaraDataInterfaceAccessibilityColorRemap();
};


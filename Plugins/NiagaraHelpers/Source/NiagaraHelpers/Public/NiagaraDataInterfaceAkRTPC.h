#pragma once
#include "CoreMinimal.h"
#include "NiagaraDataInterface.h"
#include "NiagaraDataInterfaceAkRTPC.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class NIAGARAHELPERS_API UNiagaraDataInterfaceAkRTPC : public UNiagaraDataInterface {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FName> RTPCs;
    
    UNiagaraDataInterfaceAkRTPC();
};


#pragma once
#include "CoreMinimal.h"
#include "NiagaraDataInterface.h"
#include "NiagaraCommon.h"
#include "NiagaraDataInterfaceNonUniformSpline.generated.h"

class AActor;

UCLASS(Blueprintable, EditInlineNew)
class FXUTIL_API UNiagaraDataInterfaceNonUniformSpline : public UNiagaraDataInterface {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AActor* Source;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FNiagaraUserParameterBinding SplineUserParameter;
    
    UNiagaraDataInterfaceNonUniformSpline();
};


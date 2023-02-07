#pragma once
#include "CoreMinimal.h"
#include "AISenseConfig_Cognition.h"
#include "Templates/SubclassOf.h"
#include "AISenseConfig_CogGroup.generated.h"

class UAISense_CogGroup;
class UCogGroupDebug;
class UCogGroupEvaluation;
class UCogGroupEvaluation_SecondOrder;
class UCogGroupFocusDirection;
class UCogGroupPerceiverPoint;
class UCogGroupTargetPoint;
class UCogGroupUpDirection;

UCLASS(Blueprintable, EditInlineNew)
class COGNITION_API UAISenseConfig_CogGroup : public UAISenseConfig_Cognition {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, NoClear, meta=(AllowPrivateAccess=true))
    TSubclassOf<UAISense_CogGroup> Implementation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UCogGroupFocusDirection* FocusDirectionClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UCogGroupUpDirection* UpDirectionClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UCogGroupPerceiverPoint* PerceiverPointClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float TraceRadius;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UCogGroupTargetPoint* TargetPointClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UCogGroupEvaluation*> TargetEvaluationArray;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UCogGroupEvaluation_SecondOrder*> TargetEvaluationArray_SecondOrder;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UCogGroupEvaluation*> BackgroundTargetEvaluationArray;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float PriorityBase;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bNormalizePriorityWeights;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MinBufferDistance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MaxBufferDistance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MinReevaluationTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UCogGroupDebug* DebugClass;
    
    UAISenseConfig_CogGroup();
};


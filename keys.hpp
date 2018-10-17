mpz_class DET = 14639208136976031849429148119530543286613441437463820237551079016079048817757122999049239129688518538320774528429395812167482874880_mpz;

int secret_vector[N] = {113,0,-1,-1,0,0,1,-1,0,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,0,1,0,-1,0,0,0,0,0,1,0,-1,-1,0,0,0,1,0,-1,-1,0,0,0,0,0,-1,0,0,0,0,0};
mpz_class secret_vector_inv[N] = {129560194129040325337495284534751379600659768621623597125442213405082871041010367605920741454566481391359021420863261998376368329_mpz,-482404581375115985807095342915901883520512365853094228701447639826506772890835162189684893489041492037610895984768244664103_mpz,1146442966523764850260912814852624555597971769040143767234211190007736256941090319203977413603037672740388444104626857727547881_mpz,1123626759304587436319792931664004311236225013868212063656282677274106849632968897658755429683201730920643618686118138666577913_mpz,-19507061259754495759029921848845096264879173800282784818129800528945773454921777727740380140148487570797592387367942114940151_mpz,19635885682636087183819063572243644547038062563836955928788035154469911746152660860504233461142485439383700230617202228492057_mpz,-1156562813378415100423175523245814641080436656075398485538565819370235427037704666678978916155912231031190873609895757760982999_mpz,1167219201709539194226343028753266393307360549776466673052981961768728104173629780641943732843724197188610792743197863590524473_mpz,-11409180104554498070771213532063392817829826615949461193536137223991370594990980628004908892410030172213200935756077127106231_mpz,-43106138660631592058230963017588853567080007444437046827259320688332865910079987265348091049447802284628934147467705251549863_mpz,-1127641295683476877525103091023311677796123867077046641477456521249127622488410639341643830383038218141070844577485815141307799_mpz,-728962677023860519351669965693952013328656889488681132985268301448664750941694860074208582427392423656117362188808152019847_mpz,-10279744040199405630375527448251795627044486494018757222491686108734045827592739856964510332089907169632191112978086828014711_mpz,-60294852760529018561494407725324409996308266418374494030929239292230455760457976601802771754658157715032259320663584962473063_mpz,-9012017461541529900962513297826089785008543536757204863780119055002130170993887044972061756628530578367636494915340437147479_mpz,-1167457353869529297106312218788146913672743110836929978919402012157784025722039595416131663570730380269118955639491007776619847_mpz,16807517163834165391273652801648589581508315761864131766587900457119510069536309647005214017394434071379092106770041016006089_mpz,-23837151012788052100235905659982697874846812771504570163141762928324625625900578627293789540427139144478965230997363180322343_mpz,-20145513188279572684333779136585470773550101503794180604553466938791310345117687004208083229487539737990887642736420350464279_mpz,3554020060089766966853116789347839640235645533321359631386065633520066980590808476057318981917503604892998582521915653228793_mpz,-66589041957676880262360453035177379909447446500181735643689090903278011296796829624850045213224687669357984104145784826871_mpz,-18738123000909024046902604261629884547672641960464328481646608236207257748888277858235352062429484037228035234606201570178023_mpz,-62055836989916936602559512118431140721416910598633631588908437053653936269432900730058581735500127322384188674513633175980759_mpz,-21891280279542851939897537743530144084948285438697376513568659497531604147572824150001410503016076373369872608638983626216647_mpz,28542923991595355759288137877205414294676033305230487719428559547476896341857375667190626973893229590711614264779295181646409_mpz,39202346318431577589828183812072808391851989209386118138314137384330259866744347346503429283832499167975123932562616972302937_mpz,-8762555699353775866333993781585584180016892990639555455951158227195442540658374542835361395571626779356928717921293495098519_mpz,23286059223466923022382126876721738807251874083778029896127910041765252812097152185768163067542644531749984240988976755439993_mpz,-18246215217716018971712846360443233342991115846034619460311909041084196573683635495258906980375314234101865908254137795713911_mpz,-1187271065199131582746054135692585685486163774148267650123482464008478161224344083807243807474472932217622212249063144175363943_mpz,-11243927124627585088092746838152429164283537745385510159118284302287904374277275936595739107435209866457258757436230316851799_mpz,-1853796152664357701146353859029368472443823090866228901805667054119909003166162532655138495820861617426626259382860299211847_mpz,-1125134020304183658122331795216995172154778404117450157309966597283287373159297623359097663119052335736349863720989481241405751_mpz,21059018956097806922753927575310450500027148385865870191674120641338921822209558586555924622406869206059244003969118935636697_mpz,-1155252036098706944405406872757255657645255926353855277684071956534299893952491126624778810182781957705679398138902440424334359_mpz,1996074038363283328217982463699052466358963450353151956674487531229158086433617579726256399745162389154152527325064225994233_mpz,1066108241768929110405040906721070416241509185223308967298205139089890166664631237333426774697039173788312702508936275737222409_mpz,-41055468305739029055126446062451086473277869997502107100345109652420150493548824102838218841982486901041626752573416719166183_mpz,70689125425955772289621242847062952113302517944877345735657061084190382729812758184169043995794484828247161469286932286906921_mpz,59021860673110656236538312704156327720819570839789720581787777096493065906924810297143729505353807006207791540263201325234233_mpz,31539319975231675981149185718593628426189307401141604255287598270756191746796945270598254036582819028420969409065240819238729_mpz,-17613966558383458479399767077127670310278627875980847585536249956075558299091997453687545586381740355466917249793455581137063_mpz,-1144319625569333277033488800129744589984987749804875131437743257457938966354855053677463479439669568713672139456716599846605719_mpz,347738632782339747111420939120094519255704793303262463992510264840213231312446850086568164866439956699295999213005578998393_mpz,1165821332682579968576485023522626764187305917989580211986755868926550402640405958733952780807122603496720334731469257750916489_mpz,1146700008820549610507332887642555939389860100514632487383532605872336112735696821306058960204918224854453793356774661697046937_mpz,22494163987050642810496120174639451002122456708371066142902274244448355205865646105427571500871773511493334517555910789985961_mpz,62689542407744418521022634221180577175384310590632707336061468698169271321529237014391514394588032447059494455781210370342073_mpz,39493870605866677353479284589694613611399078493251321771599969174613156615186068944495423713905545373539482036034683512745929_mpz,-1146349715773232841464726470629541144249722957131095305942766554814947624563585778950478212082222589643975981482471325723761703_mpz,-19723323931449038081680183013993635731673876893549487867638054933923105773627476223500402708322268793632119870107323774026519_mpz,1108553232464203353436442183768580769791466573042755511218901405564440914376183183072207937904941573824658662227710091963743993_mpz,1177673034551221095739075589776669603642803958028372690140279808768834340636557263736450914769918896043556599610589520721559049_mpz,18330491948862865316018355067946675009401436943959779874282730854425961380446894479075682698374822923915119000189661408087577_mpz,19271952336132446511638466292658403749183618588666917284168931008460225036274461870352657643594267950994597854296103701436201_mpz,21855807359970482918959511912520421850295242042471762984419729026900958254966698822062087604998673562304322590485867071570233_mpz,-20117506652347867597470218871247870298228115666417209544594607964445096487098419358162444230672832213209476386246413921613751_mpz,-277262425377260333280867580147956808974352081880403463570864112903387409405683837944917927979406016467882098252865451476903_mpz,1155097823167655798510369540623314379126646991844168428368818959941756604644868074325780344686427325427611794292349439713761641_mpz,19262629117763503457560721046421926462726351484607809931974428309501718795200661406121230717654578608787657039271523444271993_mpz,411152154384291632520838145901853080695026531214540294823938002135131601385013041218762690991613953914099517674935556711049_mpz,20545362730090636136641787038719111694572623600114655269561883118574460943387013321964738910836590112086000928134379911079577_mpz,-20447304920411004517957228864036440607482511671297535868835553550908736576352923309295108087840837138518144924645138527501399_mpz,20626023814835558893583552608778658877720003694632094729102104262026702019349720045029760639164477610379427437475099011413433_mpz};
